<?php
// ============================================================================
// File:    BaseAccessControl.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

require_once(__DIR__ . DIRECTORY_SEPARATOR . "AccessLevel.php");
require_once(__DIR__ . DIRECTORY_SEPARATOR . "AccessControlInterface.php");


abstract class BaseAccessControl implements AccessControlInterface
{
    abstract protected function getReadTemplates(): array;
    abstract protected function getWriteTemplates(): array;

    private function hasReadAccess(string $username, string $topic): bool
    {
        return $this->matchTopicTemplates($this->getReadTemplates(), $username, $topic);
    }

    private function hasWriteAccess(string $username, string $topic): bool
    {
        return $this->matchTopicTemplates($this->getWriteTemplates(), $username, $topic);
    }

    public function hasAccess(string $username, string $topic, int $acc): bool
    {
        if (AccessLevel::isRead($acc) && !$this->hasReadAccess($username, $topic)) {
            return false;
        }
        if (AccessLevel::isWrite($acc) && !$this->hasWriteAccess($username, $topic)) {
            return false;
        }
        return true;
    }

    private function matchTopicTemplates(array $templates, string $username, string $actualTopic): bool
    {
        foreach ($templates as $template) {
            $topic = str_replace('{{username}}', $username, $template);
            if ($actualTopic === $topic) {
                return true;
            }
        }
        return false;
    }
}

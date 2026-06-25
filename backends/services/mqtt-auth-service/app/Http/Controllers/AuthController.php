<?php
// ============================================================================
// File:    AuthController.php
// Author:  Recep Seymen Konuk <konukrecepseymen@gmail.com>
//
// Licensed under the terms of the LICENSE file in the project root directory.
// ============================================================================

namespace App\Http\Controllers;


use App\Http\Schemas\Auth\AuthenticationScheme;
use App\Http\Schemas\Auth\AuthorizationScheme;
use App\Http\Schemas\Auth\IsSuperUserScheme;

use Seymenkonuk\Framework\Controller;
use Seymenkonuk\Framework\Response;
use Seymenkonuk\Framework\Request;

use Seymenkonuk\Framework\Attribute\Prefix;
use Seymenkonuk\Framework\Attribute\Schema;
use Seymenkonuk\Framework\Attribute\Route\Post;


#[Prefix("/api/v1/auth")]
class AuthController extends Controller
{
    public function __construct(
        public Request $request,
        public Response $response,
    ) {}

    #[Post("/user")]
    #[Schema(AuthenticationScheme::class)]
    public function Authentication(): Response
    {
        $body = $this->request->body();
        // Auth Kontrolü
        // Test Amaçlı (Tüm Kullanıcıların Parolaları Kullanıcı Adı ile Aynı)
        if ($body["username"] !== $body["password"]) {
            return $this->response->forbidden();
        }
        // Success
        return $this->response->json(["allow" => true]);
    }

    #[Post("/superuser")]
    #[Schema(IsSuperUserScheme::class)]
    public function IsSuperUser(): Response
    {
        $body = $this->request->body();
        // Super User Kontrolü
        // Test Amaçlı (Yalnızca admin isimli kullanıcı super user)
        if ($body["username"] !== "admin") {
            return $this->response->forbidden();
        }
        // Success
        return $this->response->json(["allow" => true]);
    }

    #[Post("/acl")]
    #[Schema(AuthorizationScheme::class)]
    public function Authorization(): Response
    {
        $body = $this->request->body();
        // Authorization Kontrolü
        // Test Amaçlı (Tüm Kullanıcılar Yalnızca Test topic'ini Kullanabilir)
        if ($body["topic"] !== "test") {
            return $this->response->unauthorized();
        }
        // Success
        return $this->response->json(["allow" => true]);
    }
}

from flask import request
from flask_restplus import Resource, Namespace, fields
from ..services.auth import AuthService


api = Namespace("Auth")
auth_obj = api.model("AuthObj", {
    "email": fields.String(required = True),
    "password": fields.String(required = True),
    "authToken": fields.String(),
})

class AuthController:
    api = api
    @api.route("/login")
    class Login(Resource):
        @api.expect(auth_obj, validate = True)
        @api.marshal_with(auth_obj)
        def post(self):
            data = request.json
            return AuthService.login(data["email"], data["password"])

    @api.route("/sign-up")
    class Signup(Resource):
        @api.expect(auth_obj, validate = True)
        def post(self):
            data = request.json
            return AuthService.signup(data["email"], data["password"])
    
    @api.route("/validate-token")
    class ValidateToken(Resource):
        @api.marshal_with(auth_obj)
        def get(self):
            return AuthService.validate_token()

    @api.route("/delete-user")
    class DeleteUser(Resource):
        @api.marshal_with(auth_obj)
        def post(self):
            data = request.json
            return AuthService.delete_user(data["email"])
    
    @api.route("/users")
    class GetUsers(Resource):
        @api.marshal_with(auth_obj)
        def post(self):
            data = request.json
            return AuthService.delete_user(data["email"])


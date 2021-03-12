from flaskapitools import database as db
from flaskapitools.models.auth import Auth
from ..models.user import User

class AuthService:

    @staticmethod
    def signup(email, password):
        user = User(email = email, password = password)
        """ data = {
            "first_name": "Abraham",
            "Edad": 27
        }
        user.fill(data) """


        user.save()
        db.session.commit()

        session = Auth.login(email = email, password = password)

        if not session:
            return False

        
        session.set("user_id", user.id)
        session.save()

        data = {
            "email": user.email,
            "authToken": session.get("authToken")
        }

        return data

    @staticmethod
    def login(email, password):
        session = Auth.login(email = email, password = password)

        if not session:
            return False
        
        user = User.query.filter_by(email = email).first()

        session.set("user_id", user.id)
        session.save()

        data = {
            "email": user.email,
            "authToken": session.get("authToken")
        }
        
        return data

    @staticmethod
    def validate_token():
        session = Auth.get_session()

        if not session:
            return False
            
        user = User.query.filter_by(id = session.get("user_id")).first()
        
        return user

    @staticmethod
    def delete_user(email):
        user = User.query.filter_by(email = email).first()
        user.delete()
        db.session.add(user)
        db.session.commit()
        return True

    @staticmethod
    def get_users():
        users = User.query.all()
        return users

    

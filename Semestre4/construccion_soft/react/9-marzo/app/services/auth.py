from flaskapitools import database as db
from flaskapitools.models.auth import Auth
from ..models.user import User

class AuthService:

    @staticmethod
    def signup(email, password):
        user = User(email = email, password = password)
        user.save()
        db.session.commit()

        session = Auth.login(email = email, password = password)

        if not session:
            return False

        
        session.set("user_id", user.id)
        session.save()

        return session.get("auth_token")

    @staticmethod
    def login(email, password):
        session = Auth.login(email = email, password = password)

        if not session:
            return False
        
        user = User.query.filter_by(email = email).first()

        session.set("user_id", user.id)
        session.save()

        return session.get("auth_token")

    @staticmethod
    def validate_token():
        session = Auth.get_session()

        if not session:
            return False
            
        user = User.query.filter_by(id = session.get("user_id")).first()
        
        return user
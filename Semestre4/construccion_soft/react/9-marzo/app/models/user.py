from flaskapitools import database as db
from flaskapitools.models.auth import Auth
from sqlalchemy import ForeignKey
from sqlalchemy.orm import relationship

from flaskapitools.database import TimestampMixin, SoftDeleteMixin, FillableMixin

class User(Auth, TimestampMixin, SoftDeleteMixin, FillableMixin):
    __tablename__ = "user"

    id = db.Column(db.Integer, primary_key = True, autoincrement = True)
    first_name = db.Column(db.String(255))

    auth_data_id = db.Column(db.Integer, ForeignKey("auth.aid"))
    auth_data = relationship("Auth", backref = "user")

    fillable = ["first_name"]

    def save(self):
        db.session.add(self)
    
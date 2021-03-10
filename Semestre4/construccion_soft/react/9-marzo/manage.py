from flaskapitools import Api, ApiManager
from config import config
from urls import urls

#python manage.py db init
#python manage.py db migrate
#python manage.py db upgrade

application = Api(__name__, app_config = config, urls = urls)

if __name__ == '__main__':
    app = application.create_app("dev")
    manager = ApiManager(app)
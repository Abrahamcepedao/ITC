import os

class Config:
    SECRET_KEY = os.getenv("SECRET_KEY")
    DEBUG = False
    SESSIONT_TYPE = 'sqlalchemy'
    SESSION_DURATION = 1000

class DevelopmentConfig(Config):
    DEBUG = True
    SQLALCHEMY_DATABASE_URI = "mysql+pymysql://sa:Password123@jkl#@127.0.0.1/clase_dev"
    SQLALCHEMY_TRACK_MODIFICATIONS = False

class TestingConfig(Config):
    DEBUG = True
    TESTING = True
    SQLALCHEMY_DATABASE_URI = os.getenv("TEST_DATABASE_URL")
    SQLALCHEMY_TRACK_MODIFICATIONS = False

class ProductionConfig(Config):
    DEBUG = False
    TESTING = False
    SQLALCHEMY_DATABASE_URI = os.getenv("PROD_DATABASE_URL")
    SQLALCHEMY_TRACK_MODIFICATIONS = False


config = dict(
    dev = DevelopmentConfig,
    test = TestingConfig,
    prod = ProductionConfig
)
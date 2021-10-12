MySQL_CONNECTION_TIMEOUT = 30

def MySQL_connect(params):

    try:
        # Connector to MySQL dB
        import mysql.connector
        try:
            connection_timeout = params['DB_TIMEOUT']
        except:
            connection_timeout = MySQL_CONNECTION_TIMEOUT
        cnx = mysql.connector.connect(
            user=params['DB_USER'],
            password=params['DB_PASSWORD'],host=params['DB_HOST'],
            database=params['DB_NAME'], 
            auth_plugin='mysql_native_password', 
            connection_timeout=connection_timeout
        )
        return cnx
    except Exception as e:
        raise TypeError("Unable to connect to MySQL dB!:%s" % e)

def read_user_data(cnx, table_name, username):
    try:
        cursor = cnx.cursor(dictionary=True)
        username = username.replace("'", "''")
        username = username.replace('"', '""')
        # read = 'SELECT * FROM {} WHERE username = "{}"'.format(table_name, username)
        read = """
                SELECT
                *
                FROM
                {}
                WHERE
                username = %(username)s
        """.format(table_name)
        cursor.execute(read, {
                'table_name': table_name,
                'username': username
        })
        a = cursor.fetchall()
        cnx.commit()
        cursor.close()
        return a
    except Exception as e:
        raise TypeError("read_user_data:%s" % e)

def main():
    params = {'DB_USER' : 'root', 'DB_HOST' : '172.31.0.30', 'DB_PASSWORD' : 'My5ql_p4ss123.', 'DB_NAME'  : 'tc2007b', 'DB_TIMEOUT' : 10}
    connection = MySQL_connect(params)
    print("¿Qué nombre de usuario busca?")
    username = input()
    print(read_user_data(connection, 'usuarios10', username))

if __name__ == "__main__":
    main()

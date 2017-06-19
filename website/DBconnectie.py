class DbClass:
    def __init__(self):
        import mysql.connector as connector

        self.__dsn = {
            "host": "localhost",
            "user": "root",
            "passwd": "********",
            "db": "PROJECTDatabase"
        }

        self.__connection = connector.connect(**self.__dsn)
        self.__cursor = self.__connection.cursor()

    def getTemperature(self):
        # Query zonder parameters
        sql = "SELECT temperature FROM knowyourweather ORDER BY id DESC LIMIT 1"


        self.__cursor.execute(sql)
        result = self.__cursor.fetchall()
        result = str(result).replace(',)]', '')
        result = str(result).replace('[(','')
        self.__cursor.close()
        return result

    def getPressure(self):
         # Query zonder parameters
         sql = " SELECT pressure FROM knowyourweather ORDER BY id DESC LIMIT 1"

         self.__cursor.execute(sql)
         result = self.__cursor.fetchall()
         result = str(result).replace(',)]', '')
         result = str(result).replace('[(', '')
         self.__cursor.close()
         return result

    def getHumidity(self):
            # Query zonder parameters
             sql = " SELECT humidity FROM knowyourweather ORDER BY id DESC LIMIT 1"

             self.__cursor.execute(sql)
             result = self.__cursor.fetchall()

             result = str(result).replace(',)]', '')
             result = str(result).replace('[(', '')

             self.__cursor.close()
             return result

    def getRain(self):
        # Query zonder parameters
        sql = " SELECT rain FROM knowyourweather ORDER BY id DESC LIMIT 1"

        self.__cursor.execute(sql)
        result = self.__cursor.fetchall()
        result = str(result).replace(',)]', '')
        result = str(result).replace('[(', '')
        result = str(result).replace('2','no rain')
        result = str(result).replace('1','light rain')
        result = str(result).replace('0','heavy rain')
        self.__cursor.close()
        return result


        # def temperature(self, voorwaarde):
    #     # Query met parameters
    #     sqlQuery = "SELECT * FROM knowyourweather WHERE temperature = '{param1}'"
    #     # Combineren van de query en parameter
    #     sqlCommand = sqlQuery.format(param1=voorwaarde)
    #
    #     self.__cursor.execute(sqlCommand)
    #     result = self.__cursor.fetchall()
    #     self.__cursor.close()
    #     return result

    # def setDataToDatabase(self, value1):
    #     # Query met parameters
    #     sqlQuery = "INSERT INTO tablename (columnname) VALUES ('{param1}')"
    #     # Combineren van de query en parameter
    #     sqlCommand = sqlQuery.format(param1=value1)
    #
    #     self.__cursor.execute(sqlCommand)
    #     self.__connection.commit()
    #     self.__cursor.close()
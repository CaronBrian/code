
import serial
import MySQLdb as mdb

arduino = serial.Serial("/dev/ttyUSB0")
arduino.baudrate=9600

data = arduino.readline()
pieces = data.split(":")
temperature = pieces[0]
pressure = pieces[1]
humidity = pieces[2]
rain = pieces[3]


con = mdb.connect('localhost','root', '**********', 'PROJECTDatabase')

with con:
    # mysql.WriteData(temperature,pressure,humidity,rain)
    cursor = con.cursor()
    cursor.execute("""INSERT INTO knowyourweather VALUES('',%s,%s,%s,%s)""", (float(temperature),int(pressure),float(humidity),int(rain),))
    con.commit()
    cursor.close()
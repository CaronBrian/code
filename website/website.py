from flask import Flask
from flask import abort
from flask import render_template
import os
from DBconnectie import DbClass


app = Flask(__name__)


@app.route('/')
def login():

    return render_template('login.html')
@app.route('/website.html',)


def homepage():
    temperatureValues = DbClass().getTemperature()
    pressureValues = DbClass().getPressure()
    humidityValues = DbClass().getHumidity()
    rainValues = DbClass().getRain()
    return render_template('website.html',
                           temperatureValues=temperatureValues,
                           pressureValues=pressureValues,
                           humidityValues=humidityValues,
                           rainValues=rainValues)




if __name__ == '__main__':
    port = int(os.environ.get("port",8080))
    host = "169.254.10.1"

    app.run(host=host,port=port,debug=True)
# __dunder__ this is called a dunder
# Dunder or magic methods in Python are the methods having two prefix and suffix underscores in the method name. 
# Dunder here means “Double Under (Underscores)”. These are commonly used for operator overloading. 

from flask import Flask
import time
app = Flask(__name__)

@app.route("/")
def hello():
    return "Hello World - From Flask"

if __name__ == "__main__":
    app.run(host='0.0.0.0',port='3000')
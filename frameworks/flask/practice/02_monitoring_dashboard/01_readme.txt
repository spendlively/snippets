
//1. Install
./venv/bin/python3 -m pip install flask_monitoringdashboard

//2. Setup
import flask_monitoringdashboard as dashboard

app = Flask(__name__)
dashboard.bind(app)





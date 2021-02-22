import 'bootstrap/dist/css/bootstrap.css';
import './App.css';
import React from "react"
import Home from './pages/Home';


import {
  BrowserRouter as Router,
  Switch,
  Route,
} from "react-router-dom";
import MyFavoriteCity from './pages/MyFavoriteCity';
import Login from './pages/Login';
import Books from './pages/Books';


function App() {

  return (
    <Router>
      <Switch>
        <Route path="/home" component={Home}/>
        <Route path="/city" component={MyFavoriteCity}/>
        <Route path="/login" component={Login}/>
        <Route path="/books" component={Books}/>
        <Route component={Login}/>

      </Switch>
    </Router>
   
  );
}

export default App;

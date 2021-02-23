import './App.css';
import React from 'react';
import Home from './pages/Home';
import { BrowserRouter as Router, Switch, Route} from "react-router-dom";
import FavoriteCity from './pages/FavoriteCity';

function App() {
  return (
    <Router>
      <Switch>
        <Route path="/home" component={Home}/>
        <Route path="/city" component={FavoriteCity}/>
        <Route component={Home}/>
      </Switch>
    </Router>
  );
}

export default App;

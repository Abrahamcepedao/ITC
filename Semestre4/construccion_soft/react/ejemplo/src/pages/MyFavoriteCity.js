import React from "react"
import Input from "../components/Input"
import Form from "../components/Form"
import { Button, Container, Table } from "reactstrap";
import Api from "../utils/Api";
import {connect} from "react-redux"
import {selectCity, deleteCity } from "../store/actions"

class MyFavoriteCity extends React.Component{

    constructor(props) {
        super(props);
 
    }


    render(){

        return (
            <Container>
                  {JSON.stringify(this.props.city)}
        
            </Container>
        )
    }

}

const mapStateToProps = (state) => {
    return {
        city: state.cities.city
    }
}

const mapDispatchToProps = {selectCity, deleteCity}

export default connect(mapStateToProps, mapDispatchToProps)(MyFavoriteCity);
import React from 'react';
import BaseField from '../components/BaseField';
import { connect } from "react-redux";
import {selectCity, deleteCity} from "../store/actions"
import { Container } from 'reactstrap';

const form = [
  {label: "Nombre: ", defaultValue: "", type: "text"},
  {label: "Apellido paterno: ", defaultValue: "", type: "text"},
  {label: "Correo: ", defaultValue: "", type: "text"},
  {label: "Contraseña: ", defaultValue: "", type: "password"},
  {label: "Confirmación Contraseña: ", defaultValue: "", type: "password"},
]

class FavoriteCity extends BaseField{
    constructor(props){
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

export default connect(mapStateToProps, mapDispatchToProps)(FavoriteCity);

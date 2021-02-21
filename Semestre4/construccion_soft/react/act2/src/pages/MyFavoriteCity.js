import React from "react"
import { Container} from "reactstrap";
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
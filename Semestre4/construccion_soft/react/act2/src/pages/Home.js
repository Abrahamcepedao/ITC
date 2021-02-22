import React from "react"
import Input from "../components/Input"
import Form from "../components/Form"
import { Button, Container, Table } from "reactstrap";
import Api from "../utils/Api";
import {connect} from "react-redux"
import {selectCity, deleteCity } from "../store/actions"
import { withRouter } from "react-router-dom"
class Home extends React.Component{

    constructor(props) {
        super(props);
        this.state = {
            data:[]
        }
        this.input1 = React.createRef()
    }

    componentDidMount(){
        Api.GET(
            "b043df5a",
            (data)=>{
                this.setState({data:data})
            }
        )

        console.log(this.props.city)
        
    }

    displayValue = () =>{
        console.log(this.input1.current.getValue())
    }

    saveValue = () =>{
        localStorage.setItem("input1", this.input1.current.getValue())
    }

    render(){

        return (
            <Container>
                  
                <Form>
                    <Input 
                        ref={this.input1} 
                        fieldtype={"password"}
                        label={"Input 1"} 
                        defaultValue={localStorage.getItem("input1")}/>
                    
                    <Button 
                        onClick={()=>{
                            this.saveValue("input1", this.input1);
                            this.saveValue();
                            this.saveValue();

                        }}
                    >
                        Guardar en LocalStorage  valor
                    </Button>
           
                </Form>
            
                    {JSON.stringify(this.props.city)}
                    <Button
                        style={{float:"right"}}
                        color={"danger"} 
                        onClick={()=>{
                            this.props.deleteCity()
                        }}>
                        Eliminar ciudad de redux </Button>

                        <Button
                        style={{float:"right"}}
                        color={"success"} 
                        onClick={()=>{
                            this.props.history.push("/city")
                        }}>
                        Ir a la ciudad </Button>
                <Table>
                    <thead>
                        <tr>
                        <th>#</th>
                        <th>City</th>
                        <th>Name</th>
                        </tr>
                    </thead>
                    <tbody>
                        {this.state.data.map((item, index)=> 
                            <tr key={index}>
                                <th scope="row">{index+1}</th>
                                <td>{item.city}</td>
                                <td>{item.name}</td>
                                <td>
                                    <Button
                                        color={"primary"} 
                                        onClick={()=>{
                                            this.props.selectCity(item)
                                        }}>
                                        Seleccionar</Button></td>
                                    
                            </tr>)}
                    </tbody>
                </Table>
            </Container>
        )
    }

}

const mapStateToProps = (state) => {
    return {
        city: state.citiesState.city
    }
}

const mapDispatchToProps = {selectCity, deleteCity}

export default withRouter(connect(mapStateToProps, mapDispatchToProps)(Home));
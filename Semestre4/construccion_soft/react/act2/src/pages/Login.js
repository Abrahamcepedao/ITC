import React from "react"
import Input from "../components/Input"
import Form from "../components/Form"
import { Button, Container } from "reactstrap";
import {connect} from "react-redux"
import {setName, setFLastName, setMLastName, setEmail, setDate } from "../store/actions"
import { withRouter } from "react-router-dom"
class Login extends React.Component{

    constructor(props) {
        super(props);
        this.state = {
            name: "hola",
            fLastName: "",
            mLastName: "",
            email: "",
            date: "",
        }
        this.inputName = React.createRef()
        this.inputfLastName = React.createRef()
        this.inputmLastName = React.createRef()
        this.inputEmail = React.createRef()
        this.inputDate = React.createRef()
    }

    componentDidMount(){
       /*  Api.GET(
            "b043df5a",
            (data)=>{
                this.setState({data:data})
            }
        )

        console.log(this.props.city) */
        
    }

    displayValue = () =>{
        console.log(this.input1.current.getValue())
    }

    savedata = () =>{
        //localStorage.setItem("input1", this.input1.current.getValue())
        console.log("hola")
        console.log(this.inputName.current.getValue())
        localStorage.setItem("name", this.inputName.current.getValue())
        localStorage.setItem("fLastName", this.inputfLastName.current.getValue())
        localStorage.setItem("mLastName", this.inputmLastName.current.getValue())
        localStorage.setItem("email", this.inputEmail.current.getValue())
        localStorage.setItem("date", this.inputDate.current.getValue())
        this.props.setName(this.inputName.current.getValue())
        console.log("name: ", this.props.name)
    }

    render(){

        return (
            <Container>
                  
                <Form>
                    <Input 
                        ref={this.inputName} 
                        fieldtype={"text"}
                        label={"Name: "} 
                        defaultValue={localStorage.getItem("name")}
                    />
                    <Input 
                        ref={this.inputfLastName} 
                        fieldtype={"text"}
                        label={"Father Last name: "} 
                        defaultValue={localStorage.getItem("fLastName")}
                    />
                    <Input 
                        ref={this.inputmLastName} 
                        fieldtype={"text"}
                        label={"Mother last name: "} 
                        defaultValue={localStorage.getItem("mLastName")}
                    />
                    <Input 
                        ref={this.inputEmail} 
                        fieldtype={"text"}
                        label={"Email: "} 
                        defaultValue={localStorage.getItem("email")}
                    />
                    <Input 
                        ref={this.inputDate} 
                        fieldtype={"text"}
                        label={"Birthdate: "} 
                        defaultValue={localStorage.getItem("date")}
                    />
                    
                    <Button 
                        onClick={()=>{
                            this.savedata();

                        }}
                    >
                        Guardar en LocalStorage  valor
                    </Button>
           
                </Form>
            
            </Container>
        )
    }

}

const mapStateToProps = (store) => {
    return {
        name: store.userState.name
    }
}

const mapDispatchToProps = {setName, setFLastName, setMLastName, setEmail, setDate}

export default withRouter(connect(mapStateToProps, mapDispatchToProps)(Login));
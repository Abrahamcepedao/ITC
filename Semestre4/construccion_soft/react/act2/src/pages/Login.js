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
            name: "",
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
        this.props.setName(this.inputName.current.getValue())
        this.props.setFLastName(this.inputfLastName.current.getValue())
        this.props.setMLastName(this.inputmLastName.current.getValue())
        this.props.setEmail(this.inputEmail.current.getValue())
        this.props.setDate(this.inputDate.current.getValue())
        this.printData();
        this.props.history.push("/books")
        
    }

    printData = () => {
        console.log("name: ", this.props.name)
        console.log("last name: ", this.props.fLastName)
        console.log("last name: ", this.props.mLastName)
        console.log("email: ", this.props.email)
        console.log("date: ", this.props.date)
    }

    deleteData = () => {
        this.inputName.current.deleteValue()
        this.inputfLastName.current.deleteValue()
        this.inputmLastName.current.deleteValue()
        this.inputEmail.current.deleteValue()
        this.inputDate.current.deleteValue()
        localStorage.setItem("name", "")
        localStorage.setItem("fLastName", "")
        localStorage.setItem("mLastName", "")
        localStorage.setItem("email", "")
        localStorage.setItem("date", "")
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
                            this.deleteData();

                        }}
                    >
                        Limpiar
                    </Button>

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
        name: store.userState.name,
        fLastName: store.userState.fLastName,
        mLastName: store.userState.mLastName,
        email: store.userState.email,
        date: store.userState.date,
    }
}

const mapDispatchToProps = {setName, setFLastName, setMLastName, setEmail, setDate}

export default withRouter(connect(mapStateToProps, mapDispatchToProps)(Login));
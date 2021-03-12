import React from "react"
import Input from "../components/Input"
import Form from "../components/Form"
import { Button, Container } from "reactstrap";
import {connect} from "react-redux"
import { loginUser, tokenLogin } from "../store/actions"
import { withRouter } from "react-router-dom"
class Login extends React.Component{

    constructor(props) {
        super(props);
        this.state = {
            loading: true
        }
        this.email = React.createRef()
        this.password = React.createRef()
    }

    componentDidMount(){
        this.props.tokenLogin()
    }

    login = () => {
        console.log(this.email.current.getValue())
        console.log(this.password.current.getValue())

        this.props.loginUser(this.email.current.getValue(), this.password.current.getValue(), 
            () => {
                this.setState({loading: false})
            },
            () => {
                this.setState({loading: false})
            }
        )
    }

    render(){

        return (
            <Container>
                {this.state.loading ? <div>Cargando...</div> : (
                    <Form>
                        <Input type={"email"} ref={this.email}/>
                        <Input type={"password"} ref={this.password}/>
                        <Button onClick={this.login}>Login</Button>
                    </Form>
                )}
                
            
            </Container>
        )
    }

}

const mapStateToProps = (store) => {
    return {
        authToken: store.loginState.authToken
    }
}

const mapDispatchToProps = {
    loginUser,
    tokenLogin
}

export default withRouter(connect(mapStateToProps, mapDispatchToProps)(Login));
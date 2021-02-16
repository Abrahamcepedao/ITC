import React from 'react';
import BaseField from '../components/BaseField';
import Input from '../components/Input';
import Form from '../components/Form'
import { Button } from 'reactstrap';

const form = [
  {label: "Nombre: ", defaultValue: "", type: "text"},
  {label: "Apellido paterno: ", defaultValue: "", type: "text"},
  {label: "Correo: ", defaultValue: "", type: "text"},
  {label: "Contraseña: ", defaultValue: "", type: "password"},
  {label: "Confirmación Contraseña: ", defaultValue: "", type: "password"},
]

class Home extends BaseField{
    constructor(props){
        super(props);
        this.inputRef1 = React.createRef();
        this.inputRef2 = React.createRef();
        this.inputRef3 = React.createRef();
        this.inputRef4 = React.createRef();
        this.inputRef5 = React.createRef();
    }

    displayValue = () => {
        console.log(this.inputRef1.current.getValue());
        console.log(this.inputRef2.current.getValue());
        console.log(this.inputRef3.current.getValue());
        console.log(this.inputRef4.current.getValue());
        console.log(this.inputRef5.current.getValue());
    }

    saveValue = () => {
        localStorage.setItem(`inputRef1`, this.inputRef1.current.getValue())
        localStorage.setItem(`inputRef2`, this.inputRef2.current.getValue())
        localStorage.setItem(`inputRef3`, this.inputRef3.current.getValue())
        localStorage.setItem(`inputRef4`, this.inputRef4.current.getValue())
        localStorage.setItem(`inputRef5`, this.inputRef5.current.getValue())
    }

    render(){
        return (
            <div>
                <div style={{padding: '50px', background: 'rgb(245,250,250)'}}>
                    <h1 style={{textAlign: 'center'}}>Contact form</h1>
                    <div>
                        <Form>
                            <Input ref={this.inputRef1} label={form[0].label} type={form[0].type} defaultValue={localStorage.getItem("inputRef1")}/>
                            <Input ref={this.inputRef2} label={form[1].label} type={form[1].type} defaultValue={localStorage.getItem("inputRef2")}/>
                            <Input ref={this.inputRef3} label={form[2].label} type={form[2].type} defaultValue={localStorage.getItem("inputRef3")}/>
                            <Input ref={this.inputRef4} label={form[3].label} type={form[3].type} defaultValue={localStorage.getItem("inputRef4")}/>
                            <Input ref={this.inputRef5} label={form[4].label} type={form[4].type} defaultValue={localStorage.getItem("inputRef5")}/>
                        
                            <div style={{textAlign: 'center'}}>
                                <Button color="danger" style={{marginRight: '15px'}} onClick={this.displayValue}>Display Value</Button>
                                <Button color="success" onClick={this.saveValue}>Save Local Storage</Button>
                                
                            </div>
                        </Form>
                    </div>
                </div> 
            </div>
            
        )
    }

}

export default Home;

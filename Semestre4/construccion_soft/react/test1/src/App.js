import './App.css';
import Input from './components/Input';
import { Form } from 'react-bootstrap';
import { Button } from 'reactstrap';
import React from 'react';

const form = [
  {label: "Nombre: ", defaultValue: "", type: "text"},
  {label: "Apellido paterno: ", defaultValue: "", type: "text"},
  {label: "Correo: ", defaultValue: "", type: "text"},
  {label: "Contraseña: ", defaultValue: "", type: "password"},
  {label: "Confirmación Contraseña: ", defaultValue: "", type: "password"},
]

function App() {
  const input1 = React.createRef();

  const displayValue = (value) => {
    console.log(input1.current.getValue());
  }

  const changeValue = (value) => {
    input1.current.setValue("new value");
  }

  return (
    <div className="App" style={{paddding: '20px'}}>
      {/* <Counter label1="Counter 1: " label2="Counter 2: " label3="Counter 3: "/> */}
      <div style={{padding: '50px', background: 'rgb(245,250,250)'}}>
            <h1 style={{textAlign: 'center'}}>Contact form</h1>
            <div>
              <button onClick={displayValue}>Display Value</button>
              <button onClick={changeValue}>Change Value</button>
              <Input ref={input1} label={"1"} type={"text"} defaultValue={"false"}/>
              <Input ref={input1} label={"1"} type={"password"}/>
            </div>
            
            {/* {form && form.map((f, i) => (
                <Input key={i} label={f.label} type={f.type} defaultValue={f.defaultValue}/>
            ))}
            <div style={{textAlign: 'center'}}>
                <Button color="danger">Limpiar</Button>
                <Button color="success">Enviar</Button>
            </div> */}
              
      </div>  
    </div>
  );
}

export default App;

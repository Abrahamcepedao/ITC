import { TextField, Button } from '@material-ui/core';
import React, { useState, useEffect } from 'react';

const form = [
  {label: "Nombre: ", value: "", type: "text"},
  {label: "Apellido paterno: ", value: "", type: "text"},
  {label: "Correo: ", value: "", type: "text"},
  {label: "Contraseña: ", value: "", type: "password"},
  {label: "Confirmación Contraseña: ", value: "", type: "password"},
]

function ContactForm() {
    const [name, setName] = useState("");
    const [apellido, setApellido] = useState("");
    const [correo, setCorreo] = useState("");
    const [password, setPassword] = useState("");
    const [confirmPassword, setConfirmPassword] = useState("");
    const [state, setState] = useState([]);
    /* useEffect(() => {

    }, [state]) */

    const limpiar = () => {
        setName("");
        setApellido("");
        setCorreo("");
        setPassword("");
        setConfirmPassword("");
        setState([]);
    }

    const enviar = () => {
        const data = [
            {label: "Nombre: ", value: name},
            {label: "Apellido paterno: ", value: apellido},
            {label: "Correo: ", value: correo},
            {label: "Contraseña: ", value: password},
            {label: "Confirmación Contraseña: ", value: confirmPassword},
        ]
        setState(data);
    }

    return (
        <div style={{background: 'rgb(245,245,245)', textAlign: 'center', padding: '50px'}}>
            <h1>Contact form</h1>
            <form style={{padding: '50px'}}>
                <div style={{display: 'flex', marginBottom: '30px'}}>
                    <div style={{width: '50%', textAlign: 'right', padding: '10px'}}>
                        <p style={{fontWeight: 'bold'}}>Nombre: </p>
                    </div>
                    <div style={{width: '50%', textAlign: 'left', paddingLeft: '10px'}}>
                        <TextField value={name} onChange={(e) => setName(e.target.value)} placeholder={`Escribe tu nombre..`}/>
                    </div>
                </div>
                <div style={{display: 'flex', marginBottom: '30px'}}>
                    <div style={{width: '50%', textAlign: 'right', padding: '10px'}}>
                        <p style={{fontWeight: 'bold'}}>Apellido: </p>
                    </div>
                    <div style={{width: '50%', textAlign: 'left', paddingLeft: '10px'}}>
                        <TextField value={apellido} onChange={(e) => setApellido(e.target.value)} placeholder={`Escribe tu apellido..`}/>
                    </div>
                </div>
                <div style={{display: 'flex', marginBottom: '30px'}}>
                    <div style={{width: '50%', textAlign: 'right', padding: '10px'}}>
                        <p style={{fontWeight: 'bold'}}>Correo: </p>
                    </div>
                    <div style={{width: '50%', textAlign: 'left', paddingLeft: '10px'}}>
                        <TextField value={correo} onChange={(e) => setCorreo(e.target.value)} placeholder={`Escribe tu correo..`}/>
                    </div>
                </div>
                <div style={{display: 'flex', marginBottom: '30px'}}>
                    <div style={{width: '50%', textAlign: 'right', padding: '10px'}}>
                        <p style={{fontWeight: 'bold'}}>Contraseña: </p>
                    </div>
                    <div style={{width: '50%', textAlign: 'left', paddingLeft: '10px'}}>
                        <TextField value={password} onChange={(e) => setPassword(e.target.value)} placeholder={`Escribe tu contraseña..`}/>
                    </div>
                </div>
                <div style={{display: 'flex', marginBottom: '30px'}}>
                    <div style={{width: '50%', textAlign: 'right', padding: '10px'}}>
                        <p style={{fontWeight: 'bold'}}>Confirma Contraseña: </p>
                    </div>
                    <div style={{width: '50%', textAlign: 'left', paddingLeft: '10px'}}>
                        <TextField value={confirmPassword} onChange={(e) => setConfirmPassword(e.target.value)} placeholder={`Escribe tu contraseña otra vez..`}/>
                    </div>
                </div>
                <div style={{textAlign: 'center'}}>
                    <Button onClick={limpiar}>Limpiar</Button>
                    <Button onClick={enviar}>Enviar</Button>
                </div>
            </form>
            {state && state.map((item) => (
                <div>
                    <p>{item.label}</p>
                    <p>{item.value}</p>
                </div>
            ))}
        </div>
    )
}

export default ContactForm

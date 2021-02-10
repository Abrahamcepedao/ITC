import React from 'react';
import { Button, TextField } from '@material-ui/core';

class Input extends React.Component{
    constructor(props){
        super(props);
        this.state = {
            value: props.defaultValue
        }
    }



    render(){
        return (
            <div  style={{textAlign: 'center',padding: '50px', background: 'rgb(245,250,250)'}}>
                <p>{this.props.label}</p>
                <TextField placeholder="write number" value={this.state.value} onChange={(e) => {this.setState({value: e.target.value})}}/>
                <h3>{this.state.value}</h3>
            </div>
            
        )
    }

}

export default Input;

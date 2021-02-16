import React from 'react';
import BaseField from './BaseField';

class Input extends BaseField{

    render(){
        return (
            <div {...this.props}  style={{textAlign: 'center', padding: '50px'}}>
                <p>{this.props.label}</p>
                <input type={`${this.props.type}`} placeholder={`Escribe tu ${this.props.label}`} value={this.state.value} onChange={(e) => {this.setState({value: e.target.value})}}/>
            </div>
            
        )
    }

}

export default Input;

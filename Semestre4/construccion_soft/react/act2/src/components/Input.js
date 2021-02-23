import React from "react"
import BaseField from "./BaseField"
import "./Input.css"

class Input extends BaseField{

    constructor(props) {
        super(props);

    }
 
    render(){

        return (
            <div {...this.props}>
                <input className="input" type={this.props.fieldtype} placeholder={this.props.label} value={this.state.value} onChange={(e)=>{this.setState({value: e.target.value})}}/>
            </div>
        )
    }

}

export default Input;
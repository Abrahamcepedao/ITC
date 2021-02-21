import React from "react"
import BaseField from "./BaseField"


class Input extends BaseField{

    constructor(props) {
        super(props);

    }
 
    render(){

        return (
            <div {...this.props}>
                <label style={{marginRight: '20px'}}>{this.props.label}</label>
                <input type={this.props.fieldtype} value={this.state.value} onChange={(e)=>{this.setState({value: e.target.value})}}/>

                {/* <h3>{this.state.value}</h3> */}

            </div>
        )
    }

}

export default Input;
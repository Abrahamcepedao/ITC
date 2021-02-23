import React from "react"


class Form extends React.Component{

    constructor(props) {
        super(props);
    }
 
    render(){

        return (
            <div {...this.props} style={{background: 'rgb(240,240,240)', padding: '50px', marginTop: '50px', borderRadius: '25px'}}>
                
            </div>
        )
    }

}

export default Form;
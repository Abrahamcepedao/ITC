import React from 'react';
import { Button, TextField } from '@material-ui/core';

class Counter extends React.Component{
    constructor(props){
        super(props);
        this.state = {
            counter: 1,
            counterB: 1,
            counterC: 1,
            mounted: ""
        }
    }

    componentDidMount(){
        this.setState({mounted: "mounter"})
    }

    icreaseCounter = () => {
        this.setState({counter: this.state.counter + 1})
    }
    decreaseCounter = () => {
        this.setState({counter: this.state.counter - 1})
    }

    icreaseCounterB = () => {
        this.setState({counterB: this.state.counterB + 1})
    }
    decreaseCounterB = () => {
        this.setState({counterB: this.state.counterB - 1})
    }

    icreaseCounterC = () => {
        this.setState({counterC: this.state.counterC + 1})
    }
    decreaseCounterC = () => {
        this.setState({counterC: this.state.counterC - 1})
    }

    render(){
        return (
            <div  style={{textAlign: 'center',padding: '50px', background: 'rgb(245,250,250)'}}>
                <h1>Counter</h1>
                <div style={{display: 'flex'}}>
                    <Button onClick={this.decreaseCounter}>
                        -1
                    </Button>
                    <p>{this.props.label1}</p>
                    <p>{this.state.counter}</p>
                    <Button onClick={this.icreaseCounter}>
                        +1
                    </Button>
                </div>
                <div style={{display: 'flex'}}>
                    <Button onClick={this.decreaseCounterB}>
                        -1
                    </Button>
                    <p>{this.props.label2}</p>
                    <p>{this.state.counterB}</p>
                    <Button onClick={this.icreaseCounterB}>
                        +1
                    </Button>
                    
                </div>
                <div style={{display: 'flex'}}>
                    <Button onClick={this.decreaseCounterC}>
                        -1
                    </Button>
                    <p>{this.props.label3}</p>
                    <p>{this.state.counterC}</p>
                    <Button onClick={this.icreaseCounterC}>
                        +1
                    </Button>
                </div>
            </div>
            
        )
    }

}

export default Counter;

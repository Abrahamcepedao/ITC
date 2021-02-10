import './App.css';
import Counter from './components/Counter';
import Input from './components/Input';

const form = [
  {label: "Input1: ", defaultValue: "10"},
  {label: "Input2: ", defaultValue: "20"},
  {label: "Input3: ", defaultValue: "30"},
  {label: "Input4: ", defaultValue: "40"},
]

function App() {
  return (
    <div className="App">
      <Counter label1="Counter 1: " label2="Counter 2: " label3="Counter 3: "/>
      {form && form.map((f, i) => (
        <Input key={i} label={f.label} defaultValue={f.defaultValue}/>
      ))}
    </div>
  );
}

export default App;

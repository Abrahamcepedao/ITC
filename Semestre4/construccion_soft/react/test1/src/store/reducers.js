import { combineReducers } from "redux";
import cities from "./cities/reducer";

const rootReducers = combineReducers({
    cities
})

export default rootReducers
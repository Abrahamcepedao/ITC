import { combineReducers } from "redux"

import cities from "./cities/reducer";
import user from "./user/reducer";

const rootReducer = combineReducers({
    citiesState: cities,
    userState: user
})

export default rootReducer
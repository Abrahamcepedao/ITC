import { combineReducers } from "redux"

import cities from "./cities/reducer"

const rootReducer = combineReducers({
    cities
})

export default rootReducer
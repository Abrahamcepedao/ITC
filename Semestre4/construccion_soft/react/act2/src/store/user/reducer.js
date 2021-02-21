import { NAME, F_LASTNAME, M_LASTNAME, EMAIL, DATE } from "./actionType";

const INIT_STATE = {
    /* city: JSON.parse(localStorage.getItem("city")) || {} */
    name: "",
    fLastName: "",
    mLastName: "",
    email: "",
    date: null
}

const user = (state = INIT_STATE, action) => {
    switch(action.type){
        case NAME: 
            return {
                ...state,
                name: action.data
            }
        case F_LASTNAME: 
            return {
                ...state,
                fLastName: action.data
            }
        case M_LASTNAME: 
            return {
                ...state,
                mLastName: action.data
            }
        case EMAIL: 
            return {
                ...state,
                email: action.data
            }
        case DATE: 
            return {
                ...state,
                date: action.data
            }
        default:
            return state
    }
}

export default user;
import { SUCCESS_LOGIN_USER } from './actionTypes'

const initialState = {
    user: false
}

const login = (state = initialState, action) => {
    switch (action.type){
        case SUCCESS_LOGIN_USER:
            state = {
                ...state,
                user: action.payload.user
            }
            break
        default:
            state: state


    }
    return state;
}
export default login;
import { call, put, takeEvery } from "redux-saga/effects";
import { LOGIN_USER } from "./actionTypes";
import { post } from '../../utils/Api'
import { successLogin } from './actions'


function* loginUser({payload: {email, password, onSucces, OnError}}){
    try {
        let data = {
            email: email,
            password: password,
        }
        const response = yield call(post, "/auth/login", data)
        console.log(response)
        

        yield put(successLogin(response))
        onSucces(response)

    } catch(err) {
        console.log(err)
        OnError(err)
    }
}

function* tokenLogin(){
    try {
        const response = yield call(post, "/auth/validate-token")
        console.log(response)
        

        yield put(successLogin(response))

    } catch(err) {
        console.log(err)
    }
}

function* loginSaga(){
    yield takeEvery(LOGIN_USER, loginUser)
}

export default loginSaga
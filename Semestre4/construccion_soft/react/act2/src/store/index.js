import { applyMiddleware, compose, createStore } from "redux";
import createSagaMiddleWare from 'redux-saga'

import rootReducer from "./reducers"
import rootSaga from "./sagas"

const sagaMiddleWare = createSagaMiddleWare()
const composeEnhancers = window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__ || compose

const store = createStore(
    rootReducer,
    composeEnhancers(applyMiddleware(sagaMiddleWare))
)

sagaMiddleWare.run(rootSaga)

export default store
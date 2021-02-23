const axios = require('axios');

const endpoint = "https://api.mocki.io/v1/"

class Api  {
    static GET = (url, onSuccess = () => {}) => {
        axios.get(endpoint + url)
            .then(function (response) {
                // handle success
                console.log(response);
                onSuccess(response.data)
            })
            .catch(function (error) {
                // handle error
                console.log(error);
            })
            .then(function () {
                // always executed
            });
    }
    static POST = (url, data) => {

    }
    static DELETE = (url, data) => {

    }
}

export default Api
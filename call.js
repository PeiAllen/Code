/* eslint-env node, mocha */
console.log("hi");
fetch('https://dmoj.ca/api/problem/info/helloworld')
  .then(function(response) {
    return response.json();
  })
  .then(function(myJson) {
    console.log(JSON.stringify(myJson));
  });
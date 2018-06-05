const binding = require('bindings')('Winlose_nodejs');
const winlose = new binding.NJSWinlose();
console.log(` Winlose version is >>>>>  ${winlose.getVersion()}  <<<<<`)
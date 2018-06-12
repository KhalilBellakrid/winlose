const binding = require('bindings')('Winlose_nodejs');
const winlose = new binding.NJSWinlose();
console.log(winlose)
const winloseVersion = winlose.getVersion()
console.log(winloseVersion)
//console.log(` Winlose version is >>>>>  ${winlose.getVersion()}  <<<<<`)
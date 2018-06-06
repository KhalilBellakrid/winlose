const binding = require('bindings')('Winlose_nodejs');
console.log("heeeeere")
const winlose = new binding.NJSWinlose();
console.log(winlose)
const winloseVersion = winlose.getVersion()
console.log("HEEERE")
console.log(winloseVersion)
//console.log(` Winlose version is >>>>>  ${winlose.getVersion()}  <<<<<`)
rm -rf build
node-gyp configure --target_arch=x64 --msvs_version=2015 && node-gyp build
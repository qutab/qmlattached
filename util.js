.import com.ge.sigblocker 1.0 as Comp

var dataProxy = new Proxy(dataMap, {
    get(target, name) {
        console.log("get", target, name)
        if (target[name] === undefined) {
            target[name] = {"name": "default"}
        }
        return target[name]
    }
})

function getData(prop) {
    return dataProxy[prop]
}

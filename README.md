# C++ JSON Study

A study on using JSON files with C++ on an app with and update function.

I combined the class from [JSON for Modern C++](https://github.com/nlohmann/json) and combined it with a Looper class I developed (A class that repeats a function until stopped).

Basically I imagined using the JSON file for configuration in a program and allowing the viewing of modifications on the fly.

This little study uses a simple JSON file:

```json
{
  "pi": 3.141,
  "happy": true,
  "name": "Niels",
  "nothing": null,
  "answer": {
    "everything": 42
  },
  "list": [1, 0, 2],
  "object": {
    "currency": "USD",
    "value": 42.99
  },
  "stop": false,
  "maxCycles": 10
}
```

Notice the last two elements `stop` and `maxCycles`. The App uses these two values to decide when to stop itself.

If `stop` is true the app will stop as soon as possible.

If at any moment the cycle counter is greater than `maxCycles` the app will stop.

So if you have options you want to edit and immediately view the changes learn from this.

---
**NOTE**

This solution is not efficient, mainly because it is always reading the file even without any changes.

A better solution is to use [file monitoring](https://stackoverflow.com/questions/931093/how-do-i-make-my-program-watch-for-file-modification-in-c).
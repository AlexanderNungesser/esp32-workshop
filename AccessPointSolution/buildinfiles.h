const char html[] = R"(
<!DOCTYPE html>
<html lang='en'>

<head>
    <meta charset='UTF-8'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <title>WebServer Example</title>
</head>
<style>
    :root {
        --color-main-light: #ffffff;
        --color-main-dark: #000000;
        --color-main-primary: #6ec800;
        --color-main-primary-80: #8bd333;
        --color-secondary-7: #eff0f1;
        --color-secondary-15: #dedfe1;
    }

    body {
        display: flex;
        flex-direction: column;
        justify-content: space-evenly;
        font-family: 'Segoe UI', 'Segoe UI Web (West European)', 'Helvetica Neue', sans-serif;
        margin: 0;
        padding: 0;
        min-height: 100vh;
    }

    header {
        display: flex;
        flex-direction: row;
        justify-content: flex-start;
        background-color: var(--color-main-primary);
        color: var(--color-main-light);
        padding: 10px;
        align-items: center;
    }

    main {
        display: flex;
        flex-direction: column;
        flex-grow: 1;
        padding: 20px;
        background-color: var(--color-secondary-7);
    }

    footer {
        display: flex;
        justify-content: center;
        align-items: center;
        background-color: var(--color-main-primary);
        color: var(--color-main-light);
        padding: 3px;
    }

    input[type=range] {
        -webkit-appearance: none;
        width: 100%;
        height: 8px;
        background: var(--color-secondary-15);
        outline: none;
        opacity: 0.7;
        transition: opacity .2s, background-color .2s;
    }

    input[type=range]::-webkit-slider-thumb:hover {
        opacity: 1;
        background-color: var(--color-main-primary-80);
    }

    input[type=range]::-webkit-slider-thumb:active {
        opacity: 1;
        background-color: var(--color-main-primary-80);
        color: var(--color-main-dark);
        border: 1px solid var(--color-main-dark);
    }

    input[type=range]:hover {
        opacity: 1;
    }

    input[type=range]::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 20px;
        height: 20px;
        background: var(--color-main-primary);
        cursor: pointer;
        border-radius: 50%;
    }

    input[type=range]::-moz-range-thumb {
        width: 20px;
        height: 20px;
        background: var(--color-main-primary);
        cursor: pointer;
    }

    button {
        background-color: var(--color-main-primary);
        border-color: var(--color-main-primary);
        color: var(--color-main-dark);
        border-radius: 1px;
        padding: 5px 0;
        width: 75px;
        font: var(--copy);
        height: 40px;
        border: none;
        cursor: pointer;
        margin: 5px;
    }

    button:hover {
        background-color: var(--color-main-primary-80);
        color: var(--color-main-dark);
    }

    button:active {
        background-color: var(--color-main-primary-80);
        color: var(--color-main-dark);
        border: 1px solid var(--color-main-dark);
    }

    div {
        display: flex;
        flex-direction: column;
        align-items: center;
        margin-top: 10px;
    }

    label {
        align-self: flex-start;
    }
</style>

<body>

    <head>
        <header>
            <h1>WebServer Example</h1>
        </header>
    </head>
    <main>
        <div>
            <label for='servoAngle'>
                <h3>Servo Angle:</h3>
            </label>
            <input type='range' id='servoAngle' name='servoAngle' min='0' max='180' value='90'
                oninput='updateServoAngle(this.value)' onclick='handleSliderChange(this.value)' ontouchend='handleSliderChange(this.value)'>

            <h3><span id='angleValue'>90</span>°</h3>
        </div>
        <div>
            <span>
                <button onclick='moveLeft()'>Left</button>
                <button onclick='moveMiddle()'>Middle</button>
                <button onclick='moveRight()'>Right</button>
            </span>
            <div>
                <button onclick='sweep()'>Sweep</button>
            </div>
        </div>
        <script>
            function getLastPathSegment() {
                const pathSegments = window.location.pathname.split('/').filter(s => s);
                return pathSegments.length ? pathSegments[pathSegments.length - 1] : null;
            }

            function updateURL(value) {
                const newPath = `/${value}`;
                window.history.replaceState({}, '', newPath);
                location.reload();
            }

            function updateServoAngle(value) {
                document.getElementById('angleValue').textContent = value;
            }

            function handleSliderChange(value) {
                updateServoAngle(value);
                updateURL('slider?value=' + value);
            }

            function moveLeft() {
                updateURL('left');
            }

            function moveMiddle() {
                updateURL('middle');
            }

            function moveRight() {
                updateURL('right');
            }

            function sweep() {
                updateURL('sweep');
            }

            function restoreState() {
                const lastSegment = getLastPathSegment();
                const slider = document.getElementById('servoAngle');
                const angleDisplay = document.getElementById('angleValue');

                if (!lastSegment) {
                    slider.value = 90;
                    angleDisplay.textContent = 90;
                    return;
                }

                if (lastSegment === 'slider') {
                    const sliderMatch = window.location.search.match(/value=(\d+)/);
                    const value = sliderMatch[1];
                    slider.value = value;
                    angleDisplay.textContent = value;
                    console.log(`Last slider value: ${value}`);
                } else if (['left', 'middle', 'right', 'sweep'].includes(lastSegment)) {
                    let new_angle = 90;
                    switch (lastSegment) {
                        case 'left':
                            new_angle = 0;
                            break;
                        case 'right':
                            new_angle = 180;
                            break;
                        default:
                            new_angle = 90;
                            break;
                    }
                    slider.value = new_angle;
                    angleDisplay.textContent = new_angle;
                    console.log(`Last pressed button: ${lastSegment}`);
                }
            }

            window.onload = restoreState;
        </script>
    </main>
    <footer>ESP32-Workshop 2025 Wago X Ratsgymnasium</footer>
</body>

</html>)";
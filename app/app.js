
require('dotenv').config();
const puppeteer = require('puppeteer');

const wifi_ssid = process.env.WIFI_SSID;
const wifi_pass = process.env.WIFI_PASS;

async function run() {

    const browser = await puppeteer.launch({
        headless: false,
        defaultViewport: null,
        slowMo: 2,
        args: [
            '--window-position=440,310',
            '--window-size=320,600'
        ]
    });

    const pages = await browser.pages();
    const page = pages[0];

    const url = "http://192.168.4.1";

    await page.goto(url);

    await page.waitForSelector('#ssid');

    await page.type('#ssid', wifi_ssid);

    await page.waitForSelector('#pass');

    await page.type('#pass', wifi_pass);

    await page.click('input[type="submit"]');

    await new Promise(resolve => setTimeout(resolve, 2500));

    await browser.close();

}

run();

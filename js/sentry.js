const Sentry = require("@sentry/node");
const { RewriteFrames } = require("@sentry/integrations");

let sec='https://f4985d589814498ab3b0953f44ca0639@o4504164275126272.ingest.sentry.io/4504631819501568';

Sentry.init({
  dsn: sec,
  tracesSampleRate: 0.25,
  environment: "dev",
  integrations: [
    new RewriteFrames({
      root: global.__dirname,
    }),
  ],
});

Sentry.configureScope(function(scope) {
  scope.setTag("my-tag", "my value");
  scope.setUser({
    id: 42,
    email: "john.doe@example.com",
  });
});

const asd = (message)=>{
  console.log("Begin");
  try{
    if(message == 'failed') throw new Error(message);
    console.log("End");
  } catch(err){
    console.log(err.message);
    Sentry.captureException(err);
  }
}

module.exports = {
  asd,
};
using Microsoft.Owin;
using Owin;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
[assembly: OwinStartup(typeof(A9Music.Startup))]
namespace A9Music
{
    public class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            // This app does NOT create (issue) bearer tokens, but understands how to read (decrypt) and use them
            app.UseOAuthBearerAuthentication(new Microsoft.Owin.Security.OAuth.OAuthBearerAuthenticationOptions());
        }
    }
}
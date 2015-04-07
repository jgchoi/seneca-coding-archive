using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(BTI_A1.Startup))]
namespace BTI_A1
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}

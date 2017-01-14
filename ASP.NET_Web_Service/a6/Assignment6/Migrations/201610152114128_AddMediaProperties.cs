namespace Assignment6.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class AddMediaProperties : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.Album", "Photo", c => c.Binary());
            AddColumn("dbo.Album", "ContentType", c => c.String());
            AddColumn("dbo.Artist", "Photo", c => c.Binary());
            AddColumn("dbo.Artist", "ContentType", c => c.String());
            AddColumn("dbo.Track", "Clip", c => c.Binary());
            AddColumn("dbo.Track", "ContentType", c => c.String());
        }
        
        public override void Down()
        {
            DropColumn("dbo.Track", "ContentType");
            DropColumn("dbo.Track", "Clip");
            DropColumn("dbo.Artist", "ContentType");
            DropColumn("dbo.Artist", "Photo");
            DropColumn("dbo.Album", "ContentType");
            DropColumn("dbo.Album", "Photo");
        }
    }
}

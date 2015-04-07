namespace BTI_A1.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class validation : DbMigration
    {
        public override void Up()
        {
            AlterColumn("dbo.Courses", "Name", c => c.String(nullable: false));
            AlterColumn("dbo.Courses", "Code", c => c.String(nullable: false));
            AlterColumn("dbo.Courses", "Description", c => c.String(nullable: false));
        }
        
        public override void Down()
        {
            AlterColumn("dbo.Courses", "Description", c => c.String(nullable: false, maxLength: 1000));
            AlterColumn("dbo.Courses", "Code", c => c.String(nullable: false, maxLength: 10));
            AlterColumn("dbo.Courses", "Name", c => c.String(nullable: false, maxLength: 50));
        }
    }
}

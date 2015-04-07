namespace Notes.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class abcd : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.NoteBases",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        Timestamp = c.DateTime(nullable: false),
                        Title = c.String(nullable: false, maxLength: 100),
                        NoteText = c.String(nullable: false),
                        EmployeeId = c.Int(nullable: false),
                    })
                .PrimaryKey(t => t.Id);
            
        }
        
        public override void Down()
        {
            DropTable("dbo.NoteBases");
        }
    }
}

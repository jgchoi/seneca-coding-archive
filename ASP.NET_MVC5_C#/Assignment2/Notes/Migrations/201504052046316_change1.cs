namespace Notes.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class change1 : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.EmployeeBases",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        OU = c.String(),
                        FamilyName = c.String(),
                        GivenNames = c.String(),
                        IdentityUserId = c.String(),
                        BirthDate = c.DateTime(nullable: false),
                        HireDate = c.DateTime(nullable: false),
                        ManagerFullName = c.String(),
                        Discriminator = c.String(nullable: false, maxLength: 128),
                        Manager_Id = c.Int(),
                    })
                .PrimaryKey(t => t.Id)
                .ForeignKey("dbo.EmployeeBases", t => t.Manager_Id)
                .Index(t => t.Manager_Id);
            
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.EmployeeBases", "Manager_Id", "dbo.EmployeeBases");
            DropIndex("dbo.EmployeeBases", new[] { "Manager_Id" });
            DropTable("dbo.EmployeeBases");
        }
    }
}
